<?php
//1. create a connection to database
	$dbName = "store";
	$userName = "root";
	$password = "";
	$serverName = "localhost";
	
	$conn = mysqli_connect( $serverName, $userName, $password, $dbName);

//2. harvest GET variables
	$fruitName = $_GET['fruitName'];
	$price = $_GET['price'];
	$img_url = $_GET['img_url'];

//3. Create sql statment
	$sql = "INSERT INTO products
			(product_name,price,img_url)
			VALUES
			('$fruitName','$price','$img_url')
	";
echo $sql;
//4. Execute sql statement
	mysqli_query( $conn, $sql);

//5. Redirect to index.php
//	header( 'Location: index.php' );	


?>