<?php
session_start();
$conn = mysqli_connect("localhost", "root", "", "my_test_db");

if (!$conn) {
    die("Database Error: " . mysqli_connect_error());
}

$username = $_POST['username'];
$password = $_POST['password'];

$query = "SELECT * FROM login WHERE username='$username' AND password='$password'";
$result = mysqli_query($conn, $query);

if (mysqli_num_rows($result) > 0) {
    $row = mysqli_fetch_assoc($result);
    $_SESSION['username'] = $row['username'];
    $_SESSION['usertype'] = $row['usertype'];

    if ($row['usertype'] == 'admin') {
        header("Location: admin_home.html");
    } else if ($row['usertype'] == 'student') {
        header("Location: student_home.php");
    }
} else {
    echo "<script>
                alert('Database Error: " . addslashes(mysqli_error($conn)) . "');
                window.location.href = 'login.html';
              </script>";
}
?>
