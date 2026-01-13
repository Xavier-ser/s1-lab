<!DOCTYPE html>
<html>
<head>
    <title>Student Details</title>
    <style>
        body {
            background-color: #f4f7fa;
            margin: 0;
            padding: 0;
        }

        h2 {
            text-align: center;
            color: #333;
            margin-top: 40px;
        }

        table {
            border-collapse: collapse;
            margin: 30px auto;
            width: 60%;
            background-color: #fff;
            box-shadow: 0 4px 10px rgba(0,0,0,0.1);
            border-radius: 8px;
            overflow: hidden;
        }

        td {
            padding: 12px 18px;
            border-bottom: 1px solid #f6d6d6ff;
            font-size: 15px;
        }

        tr:last-child td {
            border-bottom: none;
        }

        td:first-child {
            background-color: #f0f4f8;
            font-weight: bold;
            width: 40%;
        }

        td:nth-child(2) {
            color: #444;
        }

        p {
            text-align: center;
            color: #888;
            font-size: 16px;
            margin-top: 50px;
        }

        .back-btn {
            display: block;
            width: fit-content;
            margin: 20px auto;
            padding: 10px 20px;
            background-color: #007BFF;
            color: white;
            text-decoration: none;
            border-radius: 5px;
            font-size: 14px;
        }

        .back-btn:hover {
            background-color: #0056b3;
        }
    </style>
</head>
<body>
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = htmlspecialchars($_POST['name']);
    $roll = htmlspecialchars($_POST['roll']);
    $gender = htmlspecialchars($_POST['gender']);
    $sem1 = (int)$_POST['sem1'];
    $sem2 = (int)$_POST['sem2'];
    $sem3 = (int)$_POST['sem3'];
    $total = $sem1 + $sem2 + $sem3;

    echo "<h2>Student Resume Details</h2>";
    echo "<table>";
    echo "<tr><td>Name</td><td>$name</td></tr>";
    echo "<tr><td>Roll No</td><td>$roll</td></tr>";
    echo "<tr><td>Gender</td><td>$gender</td></tr>";
    echo "<tr><td>Semester 1 Marks</td><td>$sem1</td></tr>";
    echo "<tr><td>Semester 2 Marks</td><td>$sem2</td></tr>";
    echo "<tr><td>Semester 3 Marks</td><td>$sem3</td></tr>";
    echo "<tr><td>Total Marks</td><td>$total</td></tr>";
    echo "</table>";

    echo "<a class='back-btn' href='javascript:history.back()'>← Go Back</a>";
} else {
    echo "<p>No data submitted.</p>";
}
?>
</body>
</html>
