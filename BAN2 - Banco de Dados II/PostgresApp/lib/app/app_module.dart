import 'package:dio/dio.dart';
import 'package:app_mobile/app/modules/home/cidades/aeroportos_postgres_repository.dart';
import 'package:app_mobile/app/modules/home/cidades/cidades_postgres_repository.dart';
import 'package:app_mobile/app/modules/login/login_module.dart';

import 'app_controller.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:flutter/material.dart';
import 'package:app_mobile/app/app_widget.dart';
import 'package:app_mobile/app/modules/home/home_module.dart';

import 'modules/home/checkin/checkin_postgres_repository.dart';

class AppModule extends MainModule {
  @override
  List<Bind> get binds => [
        $AppController,
        $CidadesPostgresRepository,
        $AeroportosPostgresRepository,
        $CheckinPostgresRepository,
      ];

  @override
  List<ModularRouter> get routers => [
        ModularRouter('/home', module: HomeModule()),
        ModularRouter(Modular.initialRoute, module: LoginModule()),
      ];

  @override
  Widget get bootstrap => AppWidget();

  static Inject get to => Inject<AppModule>.of();
}
