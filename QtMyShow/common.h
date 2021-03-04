#ifndef COMMON_H
#define COMMON_H

enum SlicePane {
	eXY,
	eYZ,
	eXZ,
	e3D
};

enum InteractorStyleMode{
	eStyleDefault,
	eStyleImage,//图像模式，调整窗宽窗位
	eStylePoint,//点模式，四视图联动
	eStyleOverlay//叠加
};


#endif