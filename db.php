<?php
$dsn = "odbc:Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:/DbTest/db.accdb";
$user = ""; // Leave blank if no user is set
$password = ""; // Leave blank if no password is set

try {
    $conn = new PDO($dsn, $user, $password);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    
} catch (PDOException $e) {
    die("Connection failed: " . $e->getMessage());
}
?>
