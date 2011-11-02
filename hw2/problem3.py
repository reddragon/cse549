import os
import sys
# start_sequences = set(['ATG'])
stop_sequences = set(['TGA', 'TAA', 'TAG'])

file_addr = sys.argv[1]

# orf_mode = "all" denotes considering ORFs less than 100 as well
orf_mode = ""
if(len(sys.argv) > 2):
	orf_mode = sys.argv[2]

if(len(sys.argv) > 3):
	# Logging
	log_file = sys.argv[3]
	sys.stdout = open(log_file, "w")

has_newline = 1

# This is for FASTA sequences which are on multiple lines
# Stripping the new-lines once and for all
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
				start = i/3
				end = i/3
				
		
if start >= 0:
	orf.append([start,end])

total = 0
average = 0

frequencies = { }

for f in orf:
	if orf_mode != "all" and f[1]-f[0]+1 < 100:
		continue
	
	key = ((f[1]-f[0]+1)/10)*10
	if key in frequencies:
		frequencies[key] = frequencies[key] + 1
	else:
		frequencies[key] = 1
		
	total = total + 1
	average += f[1]-f[0]+1

for key in sorted(frequencies.keys()):
	if key == 0: 
		continue
	print key, frequencies[key]

if(total == 0):
	total = 1;

# average = (average * 1.0)/total
# print "Average: ", average

