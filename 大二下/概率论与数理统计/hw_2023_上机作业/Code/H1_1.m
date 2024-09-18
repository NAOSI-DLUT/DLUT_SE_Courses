 % 产生1000个服从正态分布N(4,9)的随机变量
random_vars = normrnd(4, sqrt(9), 1000, 1);  
  
% 计算随机变量的均值和方差  
mean_value = mean(random_vars);  
variance_value = var(random_vars);  
  
% 显示结果  
fprintf('均值: %f\n', mean_value);  
fprintf('方差: %f\n', variance_value);
