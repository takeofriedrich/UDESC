import 'package:app_mobile/app/app_controller.dart';
import 'package:app_mobile/app/modules/login/interfaces/login_repository_interface.dart';
import 'package:app_mobile/app/modules/login/models/usuario.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:mongo_dart/mongo_dart.dart';

part 'login_mongo_repository.g.dart';

@Injectable()
class LoginMongoRepository extends ILoginRepository {
  AppController appController = Modular.get<AppController>();
  //dispose will be called automatically
  @override
  void dispose() {}

  @override
  Future<Usuario> realizarLogin(String usuario, String senha) {
    Modular.get<AppController>().openConnection().then((value) {
      appController.mongoConnection
          .collection('passageiros')
          .find({'usuario': usuario, 'senha': senha})
          .toList()
          .then((value) {
            appController.usuario = Usuario.fromMap(value.first);
            print(appController.usuario);
          });
    });
  }
}
