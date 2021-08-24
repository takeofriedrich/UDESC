<!DOCTYPE html>
<html lang="pt-br">

<head>
    <title>Academia</title>
    <meta charset="utf-8">
    <link rel="stylesheet" type="text/css" href="style.css">
</head>

<body>

    <?php
    $user = $senha = $id = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        if (!empty($_POST["user"])) {
            $user = $_POST["user"];
        }
        if (!empty($_POST["senha"])) {
            $senha = $_POST["senha"];
        }
    }
    ?>

    <h1 style="color:purple;text-align:center;"> Verificação de usuário e senha</h1>

    <form method="post" style="text-align:center;" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        Usuário: <input type="text" name="user"><br><br>
        Senha: <input type="password" name="senha"><br><br>
        <input type="submit" name="submit" value="Entrar">
        <input type="reset" name="reset" value="Limpar">
    </form>

    <?php

    $conexao = mysqli_connect('localhost', 'root', '', 'avaliacaoODAW', '3306');

    $resultado = mysqli_query($conexao, "select * from usuario where usuario = '$user' and senha = '$senha'");

    while ($row = $resultado->fetch_assoc()) {
        $id =  $row['id'];
    }

    if (!(empty($id))) {
        header("Location:academia.php");
    } else {
        echo '<p style="text-align:center;"> Login e Senha inválidos!';
    }

    $conexao->close();

    ?>

</body>

</html>