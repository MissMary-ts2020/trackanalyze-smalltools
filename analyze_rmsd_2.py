import MDAnalysis as mda
from MDAnalysis.analysis import rms
import numpy as np

import sys

u=mda.Universe(sys.argv[1],sys.argv[2])
#这里用参数来访问
lig=u.select_atoms("resname LIG or around 5 (resname LIG)")
u.trajectory[199]
ref=lig.atoms.copy()
rmsds=[]
file_rmsd=open("rmsd_2.csv","w")
rmsd_lig=rms.RMSD(lig,reference=ref)

rmsd_lig.run()
result=rmsd_lig.rmsd
rmsd_value_basic=result[:,2]
last_val=rmsd_value_basic[199]
rmsd_value=[0]*200
i=199
for value_basic in enumerate(rmsd_value_basic[::-1]):
    rmsd_value[i]=abs(last_val-value_basic)
    print(rmsd_value[i])
    i=i-1
i=0
for value_final in rmsd_value:
    file_rmsd.write("{0},{1}\n".format(i,rmsd_value[i]))
    i=i+1

file_rmsd.close()