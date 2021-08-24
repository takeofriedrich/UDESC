import 'package:molhei_o_pe/app/modules/home/mapas/mapas_page.dart';
import 'package:molhei_o_pe/app/modules/home/telas/tela_adicionar.dart';
import 'package:molhei_o_pe/app/modules/home/telas/tela_contato.dart';
import 'package:molhei_o_pe/app/modules/home/telas/tela_ocorrencia.dart';
import 'package:molhei_o_pe/app/modules/home/telas/tela_sobre.dart';
import 'package:molhei_o_pe/app/modules/home/telas/tela_visualizar_imagem.dart';

import 'mapas/mapas_controller.dart';
import 'package:molhei_o_pe/app/modules/home/login_repository.dart';
import 'package:molhei_o_pe/app/modules/home/mapas/mapas_repository.dart';

import 'home_controller.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'home_page.dart';

class HomeModule extends ChildModule {
  @override
  List<Bind> get binds => [
        Bind((i) => MapasController()),
        Bind((i) => HomeController()),
        Bind((i) => LoginRepository()),
        Bind((i) => MapasRepository()),
        Bind((i) => MapasPage()),
        Bind((i) => TelaAdicionar()),
        Bind((i) => TelaVisualizarImagem()),
        Bind((i) => TelaOcorrencia()),
        Bind((i) => TelaSobre()),
        Bind((i) => TelaContato()),
      ];

  @override
  List<ModularRouter> get routers => [
        ModularRouter(Modular.initialRoute, child: (_, args) => HomePage()),
      ];

  static Inject get to => Inject<HomeModule>.of();
}
