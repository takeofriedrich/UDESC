import 'package:flutter/material.dart';

class TelaSobre extends StatefulWidget {
  @override
  _TelaSobreState createState() => _TelaSobreState();
}

class _TelaSobreState extends State<TelaSobre> {
  @override
  Widget build(BuildContext context) {
    return Container(
      decoration: BoxDecoration(
        image: DecorationImage(
          image: AssetImage('images/fundo.png'),
          fit: BoxFit.cover,
        ),
      ),
      child: Column(
        mainAxisAlignment: MainAxisAlignment.start,
        children: [
          Container(
            padding: EdgeInsets.only(
                top: MediaQuery.of(context).size.width > 648 ? 120 : 90,
                left: 50,
                right: 50),
            child: Center(
              child: Column(
                children: [
                  Text(
                    'O aplicativo que não deixa você molhar os pés em Joinville!',
                    textAlign: TextAlign.center,
                    style: TextStyle(
                      fontSize: 20,
                      color: Colors.white,
                    ),
                  ),
                  Container(
                    margin: EdgeInsets.only(top: 100, left: 50, right: 50),
                    child: Text(
                      'Aplicativo criado para a disciplina de Desenvolvimento de Aplicações Web 2020.1 - UDESC CCT.',
                      textAlign: TextAlign.center,
                      style: TextStyle(
                        fontSize: 16,
                        color: Colors.white,
                      ),
                    ),
                  ),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}
