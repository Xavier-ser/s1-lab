<?php
$conn = mysqli_connect("localhost", "root", "", "my_test_db");

if (!$conn) {
    die("Connection Failed: " . mysqli_connect_error());
}

if (isset($_GET['delete'])) {
    $roll = $_GET['delete'];
    mysqli_query($conn, "DELETE FROM student WHERE roll_no = '$roll'");
    header("Location: manage_students.php");
    exit;
}

$result = mysqli_query($conn, "SELECT * FROM student");
?>

<!DOCTYPE html>
<html>
<head>
    <title>Manage Students</title>
    <style>
        table {
            border-collapse: collapse;
            width: 85%;
            margin: 30px auto;
        }
        th, td {
            padding: 12px;
            border-bottom: 1px solid #aaa;
            text-align: center;
        }
        
    </style>
</head>
<body>

<h2>Student List</h2>

<table>
    <tr>
        <th>Roll No</th>
        <th>Name</th>
        <th>Address</th>
        <th>Phone</th>
        <th>Actions</th>
    </tr>

    <?php while($row = mysqli_fetch_assoc($result)): ?>
        <tr>
            <td><?= $row['roll_no'] ?></td>
            <td><?= $row['name'] ?></td>
            <td><?= $row['address'] ?></td>
            <td><?= $row['ph_no'] ?></td>
            <td>
                <a class="btn" href="update_student.php?roll=<?= $row['roll_no'] ?>">Update</a>
                <a class="btn del" href="manage_students.php?delete=<?= $row['roll_no'] ?>"
                   onclick="return confirm('Delete this student?');">
                   Delete
                </a>
            </td>
        </tr>
    <?php endwhile; ?>

</table>

<?php mysqli_close($conn); ?>

</body>
</html>
