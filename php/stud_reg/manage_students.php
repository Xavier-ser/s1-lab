<?php
$conn = new mysqli("localhost", "root", "", "my_test_db");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// DELETE row if delete button clicked
if (isset($_GET['delete'])) {
    $roll = $_GET['delete'];
    $conn->query("DELETE FROM student WHERE roll_no = $roll");
    header("Location: manage_students.php");
    exit;
}

// Fetch all students
$result = $conn->query("SELECT * FROM student");
?>

<!DOCTYPE html>
<html>
<head>
    <title>Manage Students</title>
    <style>
        table { 
            border-collapse: collapse; 
            width: 80%; 
            margin: auto; 
        }
        th, td { 
            border: 1px solid #000; 
            padding: 10px; 
            text-align: center; 
        }
        a.btn { 
            padding: 5px 10px; 
            background: blue; 
            color: white; 
            text-decoration: none; 
            border-radius: 4px; 
            margin-right: 12px;   /* SPACE ADDED HERE */
        }
        a.del { 
            background: red; 
        }
    </style>
</head>
<body>

<h2 style="text-align:center;">Student List</h2>

<table>
    <tr>
        <th>Roll No</th>
        <th>Name</th>
        <th>Address</th>
        <th>Phone</th>
        <th>Actions</th>
    </tr>

    <?php while($row = $result->fetch_assoc()): ?>
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
</body>
</html>
