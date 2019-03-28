<?php
//1. create a connection to database
	$dbName = "store";
	$userName = "root";
	$password = "";
	$serverName = "localhost";
	
	$conn = mysqli_connect( $serverName, $userName, $password, $dbName);
//2. harvest GET variables
	$id = $_GET['id'];
	$sql = "
			DELETE FROM products
			WHERE id = $id

	";
	
//3. Create sql statment
	mysqli_query( $conn, $sql);
//4. Execute sql statement
	header( 'location: index.php' );

?>