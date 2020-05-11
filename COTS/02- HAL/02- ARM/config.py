import os
import shutil

def main():
  folder=input("Please enter the driver name: ")
  os.mkdir(folder)
  os.chdir(folder)
  config = folder+'_config.h'
  private = folder+'_private.h'
  interface = folder+'_interface.h'
  program = folder+'_program.c'
  
  configFile=open(config,'w+')  
  privateFile=open(private,'w+')
  interfaceFile=open(interface,'w+')
  programFile=open(program,'w+')
  
  c='/**************************************************** \n \t Author: Mahmoud Gamal\n************************************************/\n#ifndef '+config[:-2].upper()+ '_H\n#define '+config[:-2].upper()+'_H\n\n#endif'
  configFile.write(c)                                                                 
  p='/**************************************************** \n \t Author: Mahmoud Gamal\n************************************************/\n#ifndef '+private[:-2].upper()+ '_H\n#define '+private[:-2].upper()+'_H\n\n#endif'
  privateFile.write(p)                                                                
  i='/**************************************************** \n \t Author: Mahmoud Gamal\n************************************************/\n#ifndef '+interface[:-2].upper()+ '_H\n#define '+interface[:-2].upper()+'_H\n\n#endif'
  interfaceFile.write(i)
  p='/**************************************************** \n \t Author: Mahmoud Gamal\n************************************************/\n#include "std_types.h"\n#include "bit_math.h"\n'+'#include "'+config+'"\n'+'#include "'+private+'"\n'+'#include "'+register+'"\n'+'#include "'+interface+'"\n'
  programFile.write(p)
  
  
main()