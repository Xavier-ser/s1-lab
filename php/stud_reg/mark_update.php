<!DOCTYPE html>
<html>
<head>
    <title>Student Marks Update</title>
</head>
<body>

<?php
$conn = mysqli_connect("localhost", "root", "", "my_test_db");

if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

if (isset($_POST['update'])) {
    $roll_no = $_POST['roll_no'];
    $science = $_POST['student'];
    $maths = $_POST['maths'];
    $eng = $_POST['eng'];


    $update = "UPDATE student SET science='$science', maths='$maths', english='$eng', total='$total' WHERE roll_no='$roll_no'";
    mysqli_query($conn, $update);

    echo "<p style='color:green;'>Marks updated successfully!</p>";
}

$selected_roll = "";
$name = "";
$mark1 = "";
$mark2 = "";
$total = "";

if (isset($_POST['roll_submit'])) {
    $selected_roll = $_POST['roll_no'];
    $query = "SELECT * FROM student WHERE roll_no='$selected_roll'";
    $result = mysqli_query($conn, $query);
    if ($row = mysqli_fetch_assoc($result)) {
        $name = $row['name'];
        $science = $row['sciecne'];
        $maths = $row['maths'];
        $eng = $row['eng'];
    }
}
?>

<form method="post">
    <label>Select Roll Number:</label>
    <select name="roll_no" required>
        <option value="">--Select--</option>
        <?php
        $res = mysqli_query($conn, "SELECT roll_no FROM student");
        while ($r = mysqli_fetch_assoc($res)) {
            $selected = ($r['roll_no'] == $selected_roll) ? "selected" : "";
            echo "<option value='" . $r['roll_no'] . "' $selected>" . $r['roll_no'] . "</option>";
        }
        ?>
    </select>
    <input type="submit" name="roll_submit" value="Show Details">
</form>

<?php if ($selected_roll && $name): ?>
    <hr>
    <h3>Student Details</h3>
    <form method="post">
        <input type="hidden" name="roll_no" value="<?php echo $selected_roll; ?>">
        <p>Name: <b><?php echo htmlspecialchars($name); ?></b></p>
        <p>Science: <input type="number" name="science" value="<?php echo $science; ?>" required></p>
        <p>Maths: <input type="number" name="maths" value="<?php echo $maths; ?>" required></p>
        <p>English: <input type="number" name="eng" value="<?php echo $eng; ?>" required></p>
        <p>Total: <b><?php echo $total; ?></b></p>
        <input type="submit" name="update" value="Update Marks">
    </form>
<?php endif; ?>

<?php mysqli_close($conn); ?>

</body>
</html>
