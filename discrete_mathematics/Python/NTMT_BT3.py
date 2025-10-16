x=int(input('x= '))
y=int(input('y= '))
z=int(input('z= '))
p=(x+1==2)
q=(x+y==z)
# p-> q = (not p) or q
print('menh de suy ra: p -> q', (not p) or q)



# menh de dao: q -> p = (not q) or p
print('menh de dao: ', (not q) or p)



# menh de nghich dao: (not p ) -> (not q) = p or (not q)
print('menh de nghich dao:', p or (not q))



#menh de phan dao: (not q ) -> (not p) = q or (not p)
print('menh de phan dao:', q or (not p))






