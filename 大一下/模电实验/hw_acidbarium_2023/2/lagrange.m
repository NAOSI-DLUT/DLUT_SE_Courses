function yh=lagrange (x,y,xh)
    n = length(x);
    m = length(xh);
    yh = zeros(1,m); 
    c1 = ones(n-1,1);
    c2 = ones(1,m);
    for i=1:n
      xp = x([1:i-1 i+1:n]);
      yh = yh + y(i)*prod((c1*xh-xp'*c2)./(x(i)-xp'*c2));
    end
end