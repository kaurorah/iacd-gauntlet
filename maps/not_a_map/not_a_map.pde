import processing.serial.*;
//how to add a tooltip? some interactivity/information?
//
Table table;
Star[] stars;

void setup() {
  size(1000, 500);
  background(0);
  table = loadTable("meteorites.csv", "header");

  println(table.getRowCount() + " total rows in table"); 

  stars = new Star [table.getRowCount()];
  stroke(0);
  fill(255,200);
  int counter = 1; 
  for (TableRow row : table.rows ()) {
    //    int id = row.getInt("id");
    int mass = row.getInt("Mass");
    if (mass == 0)
      mass = 10000;
    float size = map(mass, 0, 60000000, 0, 100);
    int year = row.getInt("Year");

    Star newStar = new Star(size, year);

    mapByYear(year, size);
   // stars[counter] =newStar; 
    counter++;
  }


  int barHeight = 30; 
  rect(0, height-barHeight, width, barHeight);
}

void mapByYear(int year, float size) {
  float noiseFactor = noise(year); 
  //map to width  
  //map(value, start1, stop1, start2, stop2)
  float loc = map(year, 0, 2016, 0, width);
  ellipse(loc, (height-50)*noiseFactor, size, size);
}

