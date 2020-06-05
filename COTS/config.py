import os
import datetime


def fun():

  f=input("plz enter the folder name plz:")
  print("01-AVR \n02-STM32f10x ")
  chose =input("plz enter  1 or 2 :")
  print (chose)
  if chose == '1':
    target='AVR ATMega32 '
  else:
    target ='STM32f10x '

  d=datetime.datetime.now()
  day=str(d.day)
  month=d.strftime("%B")
  year=str(d.year)
  os.mkdir(f)
  os.chdir(f)
  filetype='This Header file '
  signature ='/**********************************************************************************************\n\
Author :Mohamed Ibrahem, Mahmoud Gamal \nVersion:1.0\nDate:'+day+' '+month+' '+year+\
  '\nDescription:'+filetype+'is used to interface with the '+f+ ' module in '+target +'evaluation kit'+'\n\
***********************************************************************************************/\n'
  f1=open(f+'_private.h','w')
  s='_private_h'
  s=s.upper()
  f1.write(signature)
  #f1.write('/************************************************************\nAuthor :Mohamed Ibrahem\nVersion:v01\nDate:'+day+' '+month+' '+year+'\n*************************************************************/\n')
  f1.write('#ifndef '+f+s+'\n')
  f1.write('#define '+f+s+'\n\n\n\n\n')
  f1.write("#endif")

  f2=open(f+'_interface.h','w')
  s='_interface_h'
  s=s.upper()
  f2.write(signature)
  #f2.write('/************************************************************\nAuthor :Mohamed Ibrahem\nVersion:v01\nDate:'+day+' '+month+' '+year+'\n*************************************************************/\n')
  f2.write('#ifndef '+f+s+'\n')
  f2.write('#define '+f+s+'\n\n\n\n\n')
  f2.write("#endif")

  f3=open(f+'_cnfg.h','w')
  s='_cnfg_h'
  s=s.upper()
  f3.write(signature)
  #f3.write('/************************************************************\nAuthor :Mohamed Ibrahem\nVersion:v01\nDate:'+day+' '+month+' '+year+'\n*************************************************************/\n')
  f3.write('#ifndef '+f+s+'\n')
  f3.write('#define '+f+s+'\n\n\n\n\n')
  f3.write("#endif")

  f5=open(f+'_register.h','w')
  s='_register_h'
  s=s.upper()
  f5.write(signature)
  #f5.write('/************************************************************\nAuthor :Mohamed Ibrahem\nVersion:v01\nDate:'+day+' '+month+' '+year+'\n*************************************************************/\n')
  f5.write('#ifndef '+f+s+'\n')
  f5.write('#define '+f+s+'\n\n\n\n\n')
  f5.write("#endif")


  filetype='This Source file '
  signature ='/**********************************************************************************************\n\
Author :Mohamed Ibrahem, Mahmoud Gamal \nVersion:1.0\nDate:'+day+' '+month+' '+year+\
  '\nDescription:'+filetype+'is used to interface with the '+f+ ' module in '+target +' evaluation kit'+'\n\
***********************************************************************************************/\n'
  f4=open(f+'_program.c','w')  
  f4.write(signature)
  f4.write('#include \"BIT_MATH.h\"\n')
  f4.write('#include \"STD_TYPES.h\"\n')
  f4.write('#include '"\""+f+'_register.h'+"\""+'\n')
  f4.write('#include '"\""+f+'_interface.h'+"\""+'\n')
  f4.write('#include '"\""+f+'_private.h'+"\""+'\n')
  f4.write('#include '"\""+f+'_cnfg.h'+"\""+'\n')
  

fun()