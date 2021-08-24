<!DOCTYPE html>
<html lang="pt-br">
<style>
    tr {
        text-align: center;
    }

    table {
        border-spacing: 5px;
    }
</style>

<head>
    <title>Academia</title>
    <meta charset="utf-8">
</head>

<script type="text/javascript">
    function validateForm() {
        return document.forms["form"]["data"].value.matches(/^\d{4}-\d{2}-\d{2}$/);
    }
</script>

<body>

    <?php
    $nome = "";
    $repet = -1;
    $series = -1;
    $carga = -1;
    $data = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        if (!empty($_POST["nome"])) {
            $nome = $_POST["nome"];
        }
        if (!empty($_POST["repet"])) {
            $repet = $_POST["repet"];
        }
        if (!empty($_POST["series"])) {
            $series = $_POST["series"];
        }
        if (!empty($_POST["carga"])) {
            $carga = $_POST["carga"];
        }
        if (!empty($_POST["data"])) {
            $data = $_POST["data"];
        }
    }
    ?>

    <h1 style="color:purple;text-align:center;">Adicionar novo treino</h2>
        <form name="form" method="post" style="text-align:center;" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" onsubmit="return validateForm();">
            <label for=" nome">Nome:</label>
            <input type="text" id="nome" name="nome" placeholder="Supino inclinado"><br><br>

            <label for="repet">Número de Repetições:</label>
            <input type="text" id="repet" name="repet" placeholder="3"><br><br>

            <label for="series">Número de Séries:</label>
            <input type="text" id="series" name="series" placeholder="10"><br><br>

            <label for="carga">Carga em KG::</label>
            <input type="text" id="carga" name="carga" placeholder="35"><br><br>

            <label for="data">Data:</label>
            <input type="text" id="data" name="data" placeholder="DD/MM/AAAA"><br><br>

            <input type="submit" value="Salvar">
            <input type="reset" value="Limpar">
        </form>

        <h1 style="color:purple;text-align:center;">Treinos cadastrados</h1>

        <table style="width:100%">

            <?php
            $conexao = mysqli_connect('localhost', 'root', '', 'avaliacaoODAW', '3306');
            $resultado = mysqli_query($conexao, 'select * from treinos');


            echo "<tr>";
            echo "<th>Id</th>";
            echo "<th>Nome</th>";
            echo "<th>Número de Repetições</th>";
            echo "<th>Número de Séries</th>";
            echo "<th>Carga em KG</th>";
            echo "<th>Data</th>";
            echo "</tr>";

            while ($row = $resultado->fetch_assoc()) {

                echo "<tr>";
                echo "<td>" . $row['id'] . "</td>";
                echo "<td>" . $row['nome'] . "</td>";
                echo "<td>" . $row['repeticoes'] . "</td>";
                echo "<td>" . $row['series'] . "</td>";
                echo "<td>" . $row['carga'] . "</td>";
                echo "<td>" . $row['data'] . "</td>";
                echo "</tr>";
            }

            if ($nome != "" && $repet != -1 && $series != -1 && $carga != -1 && $data != "") {
                $resultado = mysqli_query($conexao, "insert into treinos (nome,repeticoes,series,carga,data) values ('$nome',$repet,$series,$carga,'$data')");
                header("Location:academia.php");
            }

            ?>
        </table>

</html>