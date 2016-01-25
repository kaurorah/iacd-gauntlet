Table table;

void setup() {
  
  table = loadTable("meteorites.csv", "header");

  println(table.getRowCount() + " total rows in table"); 

  for (TableRow row : table.rows()) {
    
//    int id = row.getInt("id");
    String mass = row.getContent("Mass");
//    String name = row.getString("name");
    
    println(mass);
  }
  
}
