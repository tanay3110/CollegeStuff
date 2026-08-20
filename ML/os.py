import os

# Select the directory whose content you want to list 
directory_path = 'D:\\'  # Replace with the actual directory path

# Use the os module to list the directory content 
contents = os.listdir(directory_path)

# Print the contents of the directory 
print(contents)