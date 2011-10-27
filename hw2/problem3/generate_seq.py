from random import *

codons = 1024*1024
dna = ['A', 'C', 'G', 'T']
f = open('sequence_rand', 'w')
for x in range(codons):
	codon_str = ""
	for i in range(3):
		codon_str += (dna[randint(0,3)])
	f.write(codon_str)
f.close()
