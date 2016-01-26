import processing.serial.*;

Table table;

void setup() {
  size(1000, 500);
  background(0);
  table = loadTable("meteorites.csv", "header");

  println(table.getRowCount() + " total rows in table"); 
  stroke(255);
  //could relate to weight/mass
  strokeWeight(random(3));
  //  frameRate(4);

  //}
  //void draw(){
  for (TableRow row : table.rows ()) {

    //    int id = row.getInt("id");
    int mass = row.getInt("Mass");
        if (mass == 0)
      mass = 10000;
    float size = map(mass, 0, 60000000, 0, 30);


    int year = row.getInt("Year");
    mapByYear(year, size);
  }


  int barHeight = 30; 
  rect(0, height-barHeight, width, barHeight);
}

void mapByYear(int year, float size) {
  float noiseFactor = noise(year); 
  //map to width  
  //map(value, start1, stop1, start2, stop2)
  float loc = map(year, 0, 2016, 0, width);
  ellipse(loc, height/2*noiseFactor, size, size);
}

