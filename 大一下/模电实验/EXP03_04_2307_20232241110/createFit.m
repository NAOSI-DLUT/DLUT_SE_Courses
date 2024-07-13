function [fitresult, gof] = createFit(y, x)

%% 拟合: '无标题拟合 1'。
[xData, yData] = prepareCurveData( y, x );

% 设置 fittype 和选项。
ft = fittype( 'poly1' );

% 对数据进行模型拟合。
[fitresult, gof] = fit( xData, yData, ft );

% 绘制数据拟合图。
figure( 'Name', '直流负载曲线' );
h = plot( fitresult, xData, yData );
legend( h, '原始数据', '拟合曲线', 'Location', 'NorthEast', 'Interpreter', 'none' );
% 为坐标区加标签
xlabel( 'y', 'Interpreter', 'none' );
ylabel( 'x', 'Interpreter', 'none' );
grid on


