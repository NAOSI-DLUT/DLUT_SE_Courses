%（四） 重复问题3，但样本量从1000增至10000  
sample_size = 10000;  
uniform_vars_large = rand(sample_size, 1);  
exponential_vars_large = -3 * log(1 - uniform_vars_large);  

% 产生1000个均匀随机变量服从U(0,1)  
uniform_vars = rand(1000, 1);  
  
% 模拟产生1000个服从参数为3的指数分布的随机变量  
exponential_vars = -3 * log(1 - uniform_vars);  
  
% 计算样本均值和样本方差  
sample_mean = mean(exponential_vars);  
sample_variance = var(exponential_vars);  

% 计算大样本的样本均值和样本方差  
sample_mean_large = mean(exponential_vars_large);  
sample_variance_large = var(exponential_vars_large);  
  
% 显示结果  
fprintf('小样本均值: %f\n', sample_mean);  
fprintf('小样本方差: %f\n', sample_variance);  

% 显示结果  
fprintf('大样本均值: %f\n', sample_mean_large);  
fprintf('大样本方差: %f\n', sample_variance_large);  
  
% 比较小样本和大样本的结果  
fprintf('样本量增大时，样本均值的变化: %f\n', abs(sample_mean_large - sample_mean));  
fprintf('样本量增大时，样本方差的变化: %f\n', abs(sample_variance_large - sample_variance));
