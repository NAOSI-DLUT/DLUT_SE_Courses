syms x y z
z = sqrt(1-x^2-y^2)+1;
zx = diff(z,x);
zy = diff(z,y);
f = sqrt(1+zx^2+zy^2);
syms r t
F = subs(f,[x,y],[r*cos(t), r*sin(t)]);
syms a positive%��ΪaΪ���򸺽����ͬ������ٶ�aΪ��ʹ�������ÿ�
int(int(F*r,r,sqrt(1-a^2/4),sqrt(1-a^2/16)),t,0,2*pi)%0<|a|<2
int(int(F*r,r,0,sqrt(1-a^2/16)),t,0,2*pi)%2<=|a|<4