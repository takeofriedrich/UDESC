import 'package:flutter/material.dart';

normaliza2CasasDecimais(int valor) => valor < 10 ? '0$valor' : valor;

exibirExcecao(BuildContext context, Exception exception, String titulo) {
  showDialog(
    context: context,
    builder: (context) {
      return AlertDialog(
        title: Text(titulo),
        content: SingleChildScrollView(
          child: Text(exception.toString().replaceAll('Exception:', '')),
        ),
        actions: [
          TextButton(onPressed: Navigator.of(context).pop, child: Text('Ok')),
        ],
      );
    },
  );
}

exibirAjuda(BuildContext context, String titulo, String texto) {
  showDialog(
    context: context,
    builder: (context) {
      return AlertDialog(
        title: Text(titulo),
        content: SingleChildScrollView(
          child: Text(texto),
        ),
        actions: [
          TextButton(onPressed: Navigator.of(context).pop, child: Text('Ok')),
        ],
      );
    },
  );
}

nomeOverflow(String nome) {
  if (nome.length > 15) {
    return nome.substring(0, 15) + "...";
  } else {
    return nome;
  }
}

data(DateTime data) {
  return '${normaliza2CasasDecimais(data.day)}/${normaliza2CasasDecimais(data.month)}/${normaliza2CasasDecimais(data.year)}';
}

hora(DateTime hora) {
  return '${normaliza2CasasDecimais(hora.hour)}h${normaliza2CasasDecimais(hora.minute)}';
}
