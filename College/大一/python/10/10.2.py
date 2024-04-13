csv=open(r'C:\Users\lenovo\Desktop\score.csv')
lines=[]
for line in csv:
    line=line.replace('\n','')
    lines.append(line.split(','))
print(lines)
