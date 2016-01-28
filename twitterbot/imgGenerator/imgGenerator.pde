import com.temboo.core.*;
import com.temboo.Library.Twitter.Search.*;

// Create a session using your Temboo account application details
TembooSession session = new TembooSession("kaurorah", "myFirstApp", "4911912a88ab443db98de39b0036c871");
int counter = 5;
//56
void setup() {
  size(640, 640);
  runImgGenerator(counter);
  counter++;
  frameRate(1);
}

void draw() {
    println("counter= "+counter);

  int s = second();  // Values from 0 - 59
  int m = minute();  // Values from 0 - 59
  //  int h = hour();  //0-23
  if ((m ==20 && s == 0) ||(m ==25 && s == 0)||(m ==30 && s == 0)||(m ==35 && s == 0)||(m ==40 && s == 0)||(m ==45 && s == 0)
    ||(m ==50 && s == 0)||(m ==55 && s == 0)) {
    runImgGenerator(counter);
    counter++;
  }
}

String runLatestTweetChoreo() {
  // Create the Choreo object using your Temboo session
  LatestTweet latestTweetChoreo = new LatestTweet(session);

  // Set inputs
  latestTweetChoreo.setQuery("#blessed");
  latestTweetChoreo.setAccessToken("4840503778-HqaAunlofMeJBg9xtj1CY6aPPqNLBEKiQagihWj");
  latestTweetChoreo.setConsumerKey("lsqS9G2sj8EZdWHvUsbUA8o2p");
  latestTweetChoreo.setConsumerSecret("2HdqZEU6lgydeRI7GMAhvVAlqz2V6BV9xIeG7IZ6eSHVTtuNDz");
  latestTweetChoreo.setAccessTokenSecret("IkKO0FZmB0qaidab1XSmxAVlz3pq7YEUJTUKU6Ykq5mJk");

  // Run the Choreo and store the results
  LatestTweetResultSet latestTweetResults = latestTweetChoreo.run();

  println(latestTweetResults.getText());
  return latestTweetResults.getText();
  //  println(latestTweetResults.getResponse());
}

void runImgGenerator(int counter) {
  // Run the LatestTweet Choreo function
  String text = runLatestTweetChoreo();
  PFont font;

  font = createFont("Kreon-Bold.ttf", 48);
  textFont(font);
  //  for (int i=1; i<10; i++) {  
  PImage img;
  img = loadImage(counter+"insta.jpg");
  image(img, 0, 0);
  filter(GRAY);
  fill(100, 100);
  noStroke();
  rect(0, 0, width, height);
  fill(255);
  text(text, 0, height/3 -100, width, height -( height/3 -100) );

  saveFrame("outputImage"+counter+".jpg");
  //  }
}

