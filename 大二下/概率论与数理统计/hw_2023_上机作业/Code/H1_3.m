% 产生1000个均匀随机变量服从U(0,1)  
uniform_vars = rand(1000, 1);  
  
% 模拟产生1000个服从参数为3的指数分布的随机变量  
exponential_vars = -3 * log(1 - uniform_vars);  
  
% 计算样本均值和样本方差  
sample_mean = mean(exponential_vars);  
sample_variance = var(exponential_vars);  
  
% 指数分布的总体均值和总体方差  
population_mean = 3;  
population_variance = 3^2;  
  
% 显示结果  
fprintf('样本均值: %f\n', sample_mean);  
fprintf('样本方差: %f\n', sample_variance);  
fprintf('总体均值: %f\n', population_mean);  
fprintf('总体方差: %f\n', population_variance);
