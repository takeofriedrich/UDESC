import 'package:app_mobile/app/modules/login/excptions/usuario_nao_encontrado_excption.dart';
import 'package:app_mobile/app/modules/utils/botao_app.dart';
import 'package:app_mobile/app/modules/utils/caixa_input.dart';
import 'package:app_mobile/app/modules/utils/functions.dart';
import 'package:flutter/material.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'login_controller.dart';

class LoginPage extends StatefulWidget {
  final String title;
  const LoginPage({Key key, this.title = "Login"}) : super(key: key);

  @override
  _LoginPageState createState() => _LoginPageState();
}

class _LoginPageState extends ModularState<LoginPage, LoginController> {
  //use 'controller' variable to access controller

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.purple[300],
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: <Widget>[
          Container(
            margin: EdgeInsets.only(bottom: 15),
            height: 120,
            child: Image.asset('assets/logo.png'),
          ),
          Text(
            'Reserva de Passagens',
            style: TextStyle(color: Colors.white, fontSize: 17),
          ),
          SizedBox(
            height: 40,
          ),
          Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Container(
                padding: EdgeInsets.symmetric(horizontal: 30),
                child: CaixaInput(
                    controller: controller.caixaUsuario,
                    password: false,
                    hint: 'Nome de usuário'),
              ),
              SizedBox(
                height: 20,
              ),
              Container(
                padding: EdgeInsets.symmetric(horizontal: 30),
                child: CaixaInput(
                    controller: controller.caixaSenha,
                    password: true,
                    hint: 'Senha'),
              ),
            ],
          ),
          SizedBox(
            height: 20,
          ),
          Row(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              BotaoApp(
                text: 'Login',
                onPressed: () {
                  controller.login().catchError((e) {
                    if (!(e is UsuarioNaoEncontradoException)) {
                      exibirExcecao(context, UsuarioNaoEncontradoException(),
                          'Erro ao logar');
                    } else {
                      exibirExcecao(context, e, 'Erro ao logar');
                    }
                  });
                },
              ),
            ],
          ),
        ],
      ),
    );
  }

  _validar(String value) {
    if (value.isEmpty) {
      return "Campo obrigatório";
    }

    return null;
  }
}
