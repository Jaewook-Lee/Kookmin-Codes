import os
import time

source = ['/home/user/바탕화면/webclient-2019-01-Jaewook-Lee']
target_dir = '/home/user/backup'

if not os.path.exists(target_dir):
    os.mkdir(target_dir)

today = target_dir + os.sep + time.strftime('%Y%m%d')
now = time.strftime('%H%M%S')

target = today + os.sep + now + '.zip'

if not os.path.exists(today):
    os.mkdir(today)
    print('Successfully created directory', today)

zip_command = "zip -r {} {}" .format(target, ' '.join(source))

print("Zip command is :")
print(zip_command)
print("Running")
if os.system(zip_command) == 0:
    print("Successfully backup to", target)
else:
    print("Backup FAILED")
