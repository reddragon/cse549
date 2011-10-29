import os
import sys
start_sequence = set(['ATG'])
stop_sequences = set(['TGA', 'TAA', 'TAG'])

file_addr = sys.argv[1]
has_newline = 1

if has_newline:
	rf = open(file_addr, 'r')
	wf = open(file_addr + '.tmp', 'w')
	
	for line in rf:
		newline = line.strip('\r\n')
		wf.write(newline)
	rf.close()
	wf.close()
	os.unlink(file_addr)
	os.rename(file_addr + '.tmp', file_addr)
	
f = open(file_addr, 'r')
str = f.readline()
f.close()

start = -1
end = -1
orf = []

for i in range(len(str)):
	if i % 3 == 0:
		x = str[i:i+3]
		if(len(x) < 3): continue
		if x in stop_sequences:
			if start >= 0:
				orf.append([start,end])
			start = -1
			end = -1
		else:
			if start >= 0:
				end = end + 1
			else:
				if start == -1 and x in start_sequence:
					start = i/3
					end = i/3
				
		
if start >= 0:
	orf.append([start,end])

total = len(orf)
average = 0

for f in orf:
	print f[0], f[1], f[1]-f[0]+1
	average += f[1]-f[0]+1

average = (average * 1.0)/total
print "Average: ", average

