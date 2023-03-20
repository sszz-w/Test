# 遥感经验

> 首先要看限制条件
    1. 能否使用规定以外的数据集
    2. 不能的话,能否使用ImageNet预训练后的backbone
    3. 是否可以在训练时使用评估用的测试集
    4. 竞赛对模型推理速度有无要求
    5. 竞赛对模型的精度指标是高还是低

1. 没有数据集限制可以添加额外的数据集,增大训练集规模,提高检测器泛化性
2. 没规定不能使用测试集,可以应用**半监督学习方法**,利用已经训练好的基础检测器在未标注的测试集图片上打上伪标签，之后可以基于训练集+测试集这个更大的数据集进行模型的训练以获得在测试集上更好的精度表现，相关训练策略可以参考Pseudo-label，Noisy Student 等
3. 可以加上较新的激活函数(GELU, Swish, Mish，ACON等)、注意力机制模块、TTA、模型融合等均可作为最终提点手段(注意力机制没有使用因为用了Swin-Transformer，TTA使用的是多尺度测试与旋转增强测试，模型融合用的是最简单的results合并)
4. 精度指标为mAP@0.5: 属于中等的精度指标，TP的要求不高
5. 数据集要了解透彻,尤其是anchor based算法,要有论文最好
6. 为了保证小目标细节信息的完整性，必须采用切割的方式进行训练和测试
7. 有可能会在图像中出现超过1000个实例存在的情况，这对非密集预测的检测器有较大影响
    - 对于faster rcnn，基于coco的正负样本分配默认参数不适用Dota
    - RPN网络生成的proposals数量、RandomSampler采样器的相关参数都需重新调整
8. 目标边框长宽比的分布发现水平框和旋转框的长宽比范围也非常广，长宽比例最大接近6：1
    - anchor based检测器中的anchor scale和anchor ratios参数也需要重新调整
    - 可变形卷积网络DCN的使用在应对长宽比变化较剧烈的目标识别任务时可能会有不错的效果。（可在backbone中添加dcn结构或使用dcn类型的检测算法）
9. 类别数量占比和分布情况严重失衡，最大类别失衡比≈2000:1，网络的训练会被头部类别主导
    - 对检测速度没有要求，且这种失衡比单纯采用过/欠采样和调节各类别的loss权重效果都不会太好，所以选择为部分类别单独训练一个检测器是性价比极高的做法。
    - 同时为了平衡各个类别的分布，一些多样本数据增强策略是可以尝试的
10. 数据集类别可视化，看是否有特殊标注情况出现：其中Roundabout环形交通枢纽，存储罐Storage Tank，飞机场Airport只有水平标注，水平标注的原因：前两个因为是圆形物体，机场由于极端的长宽比无法进行旋转框的标注。
    - 为了和数据标注保持一致，数据增强中的旋转需要做特殊处理，当图片中含有Roundabout、Storage Tank、Airport这三类目标时，仅做90度倍数（90°、180°、270°）的随机旋转操作，推理时对这三类目标做最小外接水平矩形处理。