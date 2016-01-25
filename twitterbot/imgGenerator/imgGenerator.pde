void setup() {
  size(500,500);
  for (int i=1; i<10; i++) {  
    PImage img;
    img = loadImage(i+"insta.jpg");
    image(img, 0, 0);
    filter(GRAY);

//    
//    PImage newImage = createImage(img.width, img.height, ALPHA);
//    newImage = img.get();
    saveFrame("outputImage"+i+".jpg");
  }
}

