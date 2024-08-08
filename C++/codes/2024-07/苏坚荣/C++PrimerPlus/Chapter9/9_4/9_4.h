#pragma once
namespace SALES {
	const int QUARTERS = 4;
	struct Sales {
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	// 复制 ar 数组中的 4 个或 n 个元素到 s 的 sales 成员，
	// 并计算和存储输入项的平均值、最大值和最小值；
	// 剩余的 sales 元素（如果有的话）设为 0
	void setSales(Sales& s, const double ar[], int n);

	// 交互式获取 4 个季度的销售额，存储到 s 的 sales 成员中，
	// 并计算和存储平均值、最大值和最小值
	void setSales(Sales& s);

	// 显示结构 s 中的所有信息
	void showSales(const Sales& s);
}
