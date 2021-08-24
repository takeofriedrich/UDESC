import 'package:app_mobile/app/modules/home/comprar/assentos/assentos_repository_interface.dart';
import 'package:flutter_modular/flutter_modular.dart';
import 'package:dio/native_imp.dart';

part 'assentos_mongo_repository.g.dart';

@Injectable()
class AssentosMongoRepository extends IAssentosRepository {
  //dispose will be called automatically
  @override
  void dispose() {}

  @override
  Future<Map<int, bool>> listarAssentos(int codT) {
    // TODO: implement listarAssentos
    throw UnimplementedError();
  }

  @override
  Future<void> reservarAssento(int coda) {
    // TODO: implement reservarAssento
    throw UnimplementedError();
  }
}
