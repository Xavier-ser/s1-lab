<!DOCTYPE html>
<html>
<body>

<?php
$name = "";
$email = "";
$age = "";
$password = "";
$cpassword = "";
$msg = "";

if (isset($_POST['submit'])) {
    $name = trim($_POST['name']);
    $email = trim($_POST['email']);
    $age = trim($_POST['age']);
    $password = $_POST['password'];
    $cpassword = $_POST['cpassword'];

    if ($name == "" || $email == "" || $age == "" || $password == "" || $cpassword == "") {
        $msg = "All fields are required";
    } else if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
        $msg = "Invalid email";
    } else if (!is_numeric($age)) {
        $msg = "Age must be numeric";
    } else if ($password != $cpassword) {
        $msg = "Passwords do not match";
    } else {
        $msg = "Form submitted successfully";
    }
}
?>

<form method="post">
    Name: <input type="text" name="name" value="<?php echo $name; ?>"><br><br>
    Email: <input type="text" name="email" value="<?php echo $email; ?>"><br><br>
    Age: <input type="text" name="age" value="<?php echo $age; ?>"><br><br>
    Password: <input type="password" name="password"><br><br>
    Confirm Password: <input type="password" name="cpassword"><br><br>
    <input type="submit" name="submit" value="Submit">
</form>

<p><?php echo $msg; ?></p>

</body>
</html>
