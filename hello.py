#! python
from PIL import Image

import sys
img_path = sys.argv[1]
ratio = sys.argv[2]
print "image path: ", img_path
print "compression ratio: ", ratio
ratio = int(ratio)
def main():
    try:
         #Relative Path
        img = Image.open(img_path)
        width, height = img.size
  
        img = img.resize((width/ratio, height/ratio))
         
        #Saved in the same relative location
        img.save("resized_picture2.jpg") 
    except IOError:
        pass
 
if __name__ == "__main__":
    main()