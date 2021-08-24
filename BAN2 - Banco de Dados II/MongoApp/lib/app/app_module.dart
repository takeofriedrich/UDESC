import 'package:app_mobile/app/modules/home/checkin/checkin_mongo_repository.dart';
import 'package:app_mobile/app/modules/home/cidades/aeroportos_mongo_repository.dart';
import 'package:app_mobile/app/modules/home/cidades/cidades_mongo_repository.dart';
import 'package:dio/dio.dart';
import 'package:app_mobile/app/modules/login/login_module.dart';

import 'app_controller.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:flutter/material.dart';
import 'package:app_mobile/app/app_widget.dart';
import 'package:app_mobile/app/modules/home/home_module.dart';

class AppModule extends MainModule {
  @override
  List<Bind> get binds => [
        $AppController,
        $CidadesMongoRepository,
        $AeroportosMongoRepository,
        $CheckinMongoRepository,
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
