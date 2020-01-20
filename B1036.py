
line = input()
num = line.split(' ')
n = int(num[0])
ch = num[1]

for i in range(round(n/2)):
   if i == 0 or i == round(n/2)-1:
      for j in range(n):
         print(ch, end='')
      print()
   else :
      print(ch + (n-2) * ' ' + ch)




      



 















