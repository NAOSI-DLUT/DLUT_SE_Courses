# 4.7.12
# (a)
Power=function(){
  2^3
}
print(Power())

# (b)
Power2=function(x, a){
  x^a
}
print(Power2(3, 8))

# (c)
print(Power2(10, 3))
print(Power2(8, 17))
print(Power2(131, 3))

# (d)
Power3=function(x, a){
  return(x^a)
}
res=Power3(3, 8)
print(res)

# (e)
x=-20:20
plot(x,Power3(x, 2))

# (f)
PlotPower=function(x, a){
  plot(x, Power3(x, a))
}
PlotPower(1:10 ,3)
PlotPower(-20:20, 3)
