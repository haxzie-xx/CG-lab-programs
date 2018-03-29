import requests

# Student counter
count = 0

for i in range(1000, 9999):

	# SunPlus individual profile image uRL
	url = ('http://192.168.11.21/sce/displayphoto?id='+str(i)+'/CS/2017')
	try:
		r = requests.get(url, allow_redirects=True)
		# Check whether the Reg.No. Exists
		if len(r.content) > 0:
			# write the image to local file
			open('CS_2017/img_'+str(i)+'.jpg', 'wb').write(r.content)
			# got a student's photo. Yaay!
			count = count+1
			print('success: '+url)
	except:
		# wtf block
		print('ERROR: '+url)

# Show off the collected data :p
print('Total '+str(count)+' images saved!')
