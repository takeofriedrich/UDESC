import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:molhei_o_pe/app/modules/home/mapas/mapas_page.dart';
import 'package:molhei_o_pe/app/modules/home/telas/tela_adicionar.dart';
import 'package:molhei_o_pe/app/modules/home/telas/tela_contato.dart';
import 'package:molhei_o_pe/app/modules/home/telas/tela_ocorrencia.dart';
import 'package:molhei_o_pe/app/modules/home/telas/tela_sobre.dart';
import 'package:molhei_o_pe/app/modules/home/telas/tela_visualizar_imagem.dart';
import 'package:molhei_o_pe/app/modules/home/widgets/barra_inferior.dart';
import 'package:molhei_o_pe/app/modules/home/widgets/barra_logo.dart';
import 'package:molhei_o_pe/app/modules/home/widgets/barra_principal.dart';
import 'package:molhei_o_pe/app/modules/home/widgets/barra_principal_reduzido.dart';
import 'package:molhei_o_pe/app/modules/home/widgets/botao_adicionar.dart';
import 'package:molhei_o_pe/app/modules/home/widgets/botao_localizacao.dart';
import 'package:molhei_o_pe/app/modules/home/widgets/botao_retorno.dart';
import 'package:molhei_o_pe/app/modules/home/widgets/drawer_app.dart';
import 'package:molhei_o_pe/app/modules/home/widgets/foto_usuario.dart';
import 'package:molhei_o_pe/app/modules/utils/consts.dart';
import 'home_controller.dart';

class HomePage extends StatefulWidget {
  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends ModularState<HomePage, HomeController> {
  final GlobalKey<ScaffoldState> _scaffoldKey = new GlobalKey<ScaffoldState>();
  @override
  Widget build(BuildContext context) {
    // print(
    //     '${MediaQuery.of(context).size.width}  <<<<<<>>>>>> ${MediaQuery.of(context).size.height}');
    return Scaffold(
      key: _scaffoldKey,
      drawer: DrawerApp(),
      body: Stack(
        children: [
          Observer(
            builder: (BuildContext context) {
              return controller.telaSecundaria == TelaSecundaria.NENHUMA
                  ? Modular.get<MapasPage>()
                  : controller.telaSecundaria == TelaSecundaria.ADICIONAR
                      ? Modular.get<TelaAdicionar>()
                      : controller.telaSecundaria == TelaSecundaria.VISUALIZAR
                          ? Modular.get<TelaVisualizarImagem>()
                          : controller.telaSecundaria ==
                                  TelaSecundaria.OCORRENCIA
                              ? Modular.get<TelaOcorrencia>()
                              : controller.telaSecundaria ==
                                      TelaSecundaria.SOBRE
                                  ? Modular.get<TelaSobre>()
                                  : Modular.get<TelaContato>();
            },
          ),
          MediaQuery.of(context).size.width > 648
              ? BarraPrincipal(
                  layout: MediaQuery.of(context).size.width < 1216
                      ? BarraPrincipalLayout.DIVIDIDO
                      : BarraPrincipalLayout.NORMAL,
                )
              : BarraPrincipalReduzido(
                  onTapMenu: () {
                    _scaffoldKey.currentState.openDrawer();
                  },
                ),
          Container(
            margin: EdgeInsets.only(top: 52),
            height: 3,
            width: MediaQuery.of(context).size.width,
            color: Colors.white,
          ),
          MediaQuery.of(context).size.width > 648
              ? Observer(
                  builder: (BuildContext context) {
                    return (controller.telaSecundaria ==
                                TelaSecundaria.ADICIONAR ||
                            controller.telaSecundaria ==
                                TelaSecundaria.OCORRENCIA)
                        ? Align(
                            alignment: Alignment.topLeft,
                            child: BotaoRetorno(),
                          )
                        : Container();
                  },
                )
              : Container(),
          MediaQuery.of(context).size.width > 648
              ? Align(
                  alignment: Alignment.topCenter,
                  child: BarraLogo(),
                )
              : Container(),
          MediaQuery.of(context).size.width > 648
              ? Align(
                  alignment: Alignment.bottomCenter,
                  child: BarraInferior(),
                )
              : Container(),
          Observer(
            builder: (BuildContext context) {
              return controller.telaSecundaria == TelaSecundaria.NENHUMA
                  ? Align(
                      alignment: Alignment.bottomLeft,
                      child: BotaoAdicionar(
                        bottom: MediaQuery.of(context).size.width > 648
                            ? controller.user != null
                                ? 200
                                : 45
                            : 30,
                        left: MediaQuery.of(context).size.width > 648
                            ? controller.user != null
                                ? 90
                                : 60
                            : 45,
                      ),
                    )
                  : Container();
            },
          ),
          Observer(
            builder: (context) => controller.telaSecundaria ==
                    TelaSecundaria.NENHUMA
                ? Align(
                    child: BotaoLocalizacao(
                      bottom: MediaQuery.of(context).size.width > 648 ? 45 : 30,
                      right: MediaQuery.of(context).size.width > 648 ? 70 : 30,
                    ),
                    alignment: Alignment.bottomRight,
                  )
                : Container(),
          ),
          MediaQuery.of(context).size.width > 648
              ? Observer(
                  builder: (BuildContext context) {
                    return controller.user != null &&
                            controller.telaSecundaria == TelaSecundaria.NENHUMA
                        ? Align(
                            alignment: Alignment.bottomLeft,
                            child: GestureDetector(
                              onTap: () {
                                exibirOcorrencias(
                                    'Número de cadastros: ${controller.numeroOcorrencias}');
                              },
                              child: FotoUsuario(),
                            ),
                          )
                        : Container();
                  },
                )
              : Container(),
        ],
      ),
    );
  }

  exibirOcorrencias(String text) {
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
