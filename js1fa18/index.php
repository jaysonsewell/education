<?php
	echo "<h1>Welcome to Jay's Store</h1>";
	//comment
	//1. Get DB connection strings
	$dbName = "store";
	$userName = "root";
	$password = "";
	$serverName = "localhost";
	
	$conn = mysqli_connect( $serverName, $userName, $password, $dbName);
	
	//2. Connect to DB and get strings
	if( !$conn){
		die("Connection Failed: ".mysqli_connect_error() );
	}
	
	$sql = "SELECT * FROM products";
	$results = mysqli_query( $conn, $sql);
	
	//3. Turn DB into html
	while( $row = mysqli_fetch_assoc( $results ) ) {
		$id = $row['id'];
		$product_name = $row['product_name'];
		$price = $row['price'];
		$img_url = $row['img_url'];
		echo "
		<h2>$product_name</h2>
		<img src='$img_url' height='100'> <br>
		<b>Price:</b>$price
		<a href='delete.php?id=$id'>Delete $id </a>
		";
		
	}
	
?>
<h1>Enter New Fruit</h1>
<form method="GET" action="insert.php">
Name:	<input type="text" name="fruitName" require><br>
Price:	<input type="number" name="price" require><br>
url:	<input type="url" name="img_url" require><br>
<input type="submit" value="Enter new fruit">

</form>
