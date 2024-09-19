% 标准化随机变量  
standardized_vars = (random_vars - mean_value) / sqrt(variance_value);  
  
% 计算新随机变量的均值和方差  
mean_standardized = mean(standardized_vars);  
variance_standardized = var(standardized_vars);  
  
% 显示结果  
fprintf('标准化后均值: %f\n', mean_standardized);  
fprintf('标准化后方差: %f\n', variance_standardized);