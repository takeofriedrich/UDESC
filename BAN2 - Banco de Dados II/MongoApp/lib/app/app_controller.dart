import 'package:app_mobile/app/modules/login/models/usuario.dart';

import 'package:mobx/mobx.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:mongo_dart/mongo_dart.dart';
part 'app_controller.g.dart';

@Injectable()
class AppController = _AppControllerBase with _$AppController;

abstract class _AppControllerBase with Store {
  Usuario usuario;
  Db mongoConnection = Db('mongodb://10.0.2.2:27017/trabBan');

  Future<void> openConnection() async {
    await mongoConnection.open();
  }
}
