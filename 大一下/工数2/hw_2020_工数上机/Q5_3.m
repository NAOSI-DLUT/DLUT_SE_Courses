syms a t
x = a*cos(t)*sqrt(2)/2;
y = a*cos(t)*sqrt(2)/2;
z = a*sin(t);
dy = diff(y,t);
dz = diff(z,t);
int(sqrt(2*y^2+z^2)*sqrt(2*dy^2+dz^2),t,0,2*pi)
