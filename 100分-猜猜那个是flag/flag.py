import random

flag = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',0,1,2,3,4,5,6,7,8,9,'+','/']
the_random_flag="";

for n in range(100):
	the_random_flag ="";
	for m in range(18):
		which = random.randint(0,63)
		the_random_flag += str(flag[which])
	
	print("flag{" + the_random_flag +"}"+"\n")