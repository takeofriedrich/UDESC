import 'package:clipboard/clipboard.dart';
import 'package:flutter/material.dart';
import 'package:molhei_o_pe/app/modules/utils/consts.dart';

class TelaContato extends StatefulWidget {
  @override
  _TelaContatoState createState() => _TelaContatoState();
}

class _TelaContatoState extends State<TelaContato> {
  @override
  Widget build(BuildContext context) {
    return Container(
      decoration: BoxDecoration(
        image: DecorationImage(
          image: AssetImage('images/fundo.png'),
          fit: BoxFit.cover,
        ),
      ),
      child: ListView(
        children: [
          Container(
            padding: EdgeInsets.only(
                top: MediaQuery.of(context).size.width > 648 ? 120 : 90),
            child: Center(
              child: Text(
                'Autores:',
                style: TextStyle(fontSize: 20, color: Colors.white),
              ),
            ),
          ),
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Container(
                padding: EdgeInsets.only(top: 50, bottom: 15),
                child: Text(
                  'Matias Giuliano Gutierrez Benitez',
                  style: TextStyle(fontSize: 17, color: Colors.white),
                ),
              ),
            ],
          ),
          _exibirInfo(
              'Email: ', 'matiguti17@gmail.com', 'matiguti17@gmail.com'),
          _exibirInfo(
              'Github: ', 'github.com/matiguti', 'https://github.com/matiguti'),
          _exibirInfo('Instagram: ', '@matiguti_',
              'https://www.instagram.com/matiguti_/'),
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              Container(
                padding: EdgeInsets.only(top: 50, bottom: 15),
                child: Text(
                  'Vinicius Takeo Friedrich Kuwaki',
                  style: TextStyle(fontSize: 17, color: Colors.white),
                ),
              ),
            ],
          ),
          _exibirInfo('Email: ', 'vtkwki@gmail.com', 'vtkwki@gmail.com'),
          _exibirInfo('Github: ', 'github.com/takeofriedrich',
              'https://github.com/takeofriedrich'),
          _exibirInfo('Instagram: ', '@takeofriedrich',
              'https://www.instagram.com/takeofriedrich/'),
          SizedBox(
            height: 50,
          ),
        ],
      ),
    );
  }

  _exibirInfo(String titulo, String texto, String link) {
    final childrens = [
      Container(
        padding: EdgeInsets.only(top: 10),
        child: Text(
          titulo,
          style: TextStyle(fontSize: 15, color: Colors.white),
        ),
      ),
      Container(
        padding: EdgeInsets.only(top: 10),
        child: InkWell(
          onTap: () {
            FlutterClipboard.copy(link).then((value) {
              dialogo('Link copiado!');
            });
          },
          child: Text(
            link,
            style: TextStyle(
              fontSize: 15,
              color: Colors.white,
              decoration: TextDecoration.underline,
            ),
          ),
        ),
      ),
    ];
    return MediaQuery.of(context).size.width > 648
        ? Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: childrens,
          )
        : Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: childrens,
          );
  }

  dialogo(String text) {
    showDialog(
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          backgroundColor: ROXO_APP,
          content: Text(
            text,
            style: TextStyle(color: Colors.white),
            textAlign: TextAlign.center,
          ),
          actions: [
            TextButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              child: Container(
                child: Text(
                  'Confirmar',
                  style: TextStyle(color: Colors.white),
                ),
                margin: EdgeInsets.only(right: 5),
              ),
            )
          ],
        );
      },
    );
  }
}
