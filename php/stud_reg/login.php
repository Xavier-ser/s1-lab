<?php
if($_SERVER["REQUEST_METHOD"]=="POST"){

$conn = mysqli_connect("localhost", "root", "", "my_test_db");

if (!$conn) {
    die("Database Error: " . mysqli_connect_error());
}


$username = $_POST['username'] ;
$password = $_POST['password'] ;

$query = "SELECT * FROM login WHERE username='$username' AND password='$password'";
$result = mysqli_query($conn, $query);

echo $result;

if (mysqli_num_rows($result) > 0) {

        header("Location: admin_home.html");

    // $row = mysqli_fetch_assoc($result);

    // if ($row['usertype'] == 'admin') {
    //     header("Location: admin_home.html");
    // }
} else {
    echo "<script>
                alert('Incorrect " . addslashes(mysqli_error($conn)) . "');
                window.location.href = 'login.html';
              </script>";
}
}
?>
