import 'assentos/assentos_mongo_repository.dart';
import 'trechos/trechos_mongo_repository.dart';
import 'package:dio/dio.dart';
import 'voos/voos_mongo_repository.dart';

import 'package:app_mobile/app/modules/home/comprar/assentos/assentos_controller.dart';
import 'package:app_mobile/app/modules/home/comprar/assentos/assentos_page.dart';

import 'package:app_mobile/app/modules/home/comprar/trechos/trechos_controller.dart';
import 'package:app_mobile/app/modules/home/comprar/trechos/trechos_page.dart';

import 'package:app_mobile/app/modules/home/comprar/voos/voos_page.dart';

import 'voos/voos_controller.dart';
import 'voos/reservas_postgres_repository.dart';
import 'package:app_mobile/app/modules/home/comprar/pages/selecionar_destino/selecionar_destino_controller.dart';
import 'package:app_mobile/app/modules/home/comprar/pages/selecionar_destino/selecionar_destino_page.dart';
import 'package:app_mobile/app/modules/home/comprar/pages/selecionar_origem/selecionar_origem_controller.dart';
import 'package:app_mobile/app/modules/home/comprar/pages/selecionar_origem/selecionar_origem_page.dart';

import 'comprar_controller.dart';
import 'package:flutter_modular/flutter_modular.dart';

import 'comprar_page.dart';

class ComprarModule extends ChildModule {
  @override
  List<Bind> get binds => [
        $AssentosMongoRepository,
        $TrechosMongoRepository,
        $VoosMongoRepository,
        $AssentosController,
        $VoosController,
        $ReservasPostgresRepository,
        $SelecionarDestinoController,
        $SelecionarOrigemController,
        $ComprarController,
      ];

  @override
  List<ModularRouter> get routers => [
        ModularRouter(Modular.initialRoute, child: (_, args) => ComprarPage()),
        ModularRouter('/origem', child: (_, args) => SelecionarOrigemPage()),
        ModularRouter('/destino', child: (_, args) => SelecionarDestinoPage()),
        ModularRouter('/voos', child: (_, args) => VoosPage()),
        ModularRouter('/trechos', child: (_, args) => TrechosPage()),
        ModularRouter('/assentos', child: (_, args) => AssentosPage()),
      ];

  static Inject get to => Inject<ComprarModule>.of();
}
